#include <iostream>

class Buffer {
       public:
           Buffer();
           Buffer(size_t size);
           Buffer(Buffer const& other);
           Buffer& operator=(Buffer const& other);
           virtual ~Buffer();
           DSG::DSGSample& operator[](size_t const& index);
           inline size_t const& Size()const;
       protected:
           DSG::DSGSample* _buffer;
           size_t _size;
       };
       inline size_t const& DSG::Buffer::Size()const{
           return _size;
       }
//implementation
DSG::Buffer::Buffer():_size(0),_buffer(nullptr){}
DSG::Buffer::Buffer(size_t size):_size(size),_buffer(new DSG::DSGSample[size]){}
DSG::Buffer::Buffer(Buffer const& other) {
       _buffer = new  DSG::DSGSample[_size];
       _size = other._size;
          *this = other;
}
DSG::Buffer& DSG::Buffer::operator=(Buffer const& other){
       if (_size!=other._size) {
           if (_buffer!=nullptr) {
               delete [] _buffer;
           }
           _size = other._size;
           _buffer = new  DSG::DSGSample[_size];
       }
       for (int i=0; i<_size; ++i) {
           _buffer[i] = other._buffer[i];
       }
       return *this;
}
DSG::Buffer::~Buffer(){
       if (_buffer!=nullptr) {
           delete [] _buffer;
       }
}
DSG::DSGSample& DSG::Buffer::operator[](size_t const& index){
#ifdef DEBUG
       assert(index<_size);
#endif
       return _buffer[index];
}

//ringbuffer
class RingBuffer:public DSG::Buffer {
       protected:
           std::atomic<size_t> _write;
           std::atomic<size_t> _read;
           size_t _count;
           size_t MASK;
           size_t write;
           size_t read;
           inline size_t next(size_t current);
           inline size_t make_pow_2(size_t number);
       public:
           RingBuffer();
           RingBuffer(const size_t size);
           RingBuffer(RingBuffer& buffer);
           RingBuffer& operator=(RingBuffer& buffer);
           virtual ~RingBuffer();
           inline bool Write(const DSGSample& elem);
           inline bool Read(DSG::DSGSample& elem);
           inline size_t const& Count()const;
           inline bool Full()const;
           inline bool Empty()const;
           inline void Flush();
           friend bool operator>>(DSG::DSGSample const& signal,DSG::RingBuffer& buffer){
               return buffer.Write(signal);
           }
           friend bool operator<<(DSG::DSGSample& signal,DSG::RingBuffer& buffer){
               return buffer.Read(signal);
           }
#ifdef DEBUG
           friend std::ostream& operator<<(std::ostream& os,DSG:: RingBuffer const& buffer){
               if (!buffer.Empty()) {
                   size_t index= buffer._read;
                   size_t count=buffer.Count();
                   size_t size = buffer.Size();
                   for (int i=0; i<count; ++i) {
                       os<<index<<": "<<buffer._buffer[index]<<std::endl;
                       index = ((index+1)%size);
                   }
               }return os;
           }
#endif
       };
       inline bool DSG::RingBuffer::Full()const{
           return _count==this->_size;
       }
       inline bool DSG::RingBuffer::Empty()const{
           return _count==0;
       }
       inline void DSG::RingBuffer::Flush(){
           _write.store(0,std::memory_order_relaxed);
           _read.store(0,std::memory_order_relaxed);
           _count=0;
       }
       inline bool DSG::RingBuffer::Write(const DSGSample& elem){
           if (!Full()) {
               write = _write.load(std::memory_order_acquire);
               _write.store(next(write),std::memory_order_release);
               this->_buffer[write] = elem;
               ++_count;
               return true;
           }else return false;
       }
       inline bool DSG::RingBuffer::Read(DSGSample& elem){
           if (!Empty()) {
               read = _read.load(std::memory_order_acquire);
               _read.store(next(read),std::memory_order_release);
               elem = this->_buffer[read];
               --_count;
               return true;
           }else return false;
       }
       inline size_t const& DSG::RingBuffer::Count()const{
           return _count;
       }
       //note: RingBuffer implementation will force a power of 2 size to allow use of bitwise increment.
       inline size_t DSG::RingBuffer::next(size_t current){return (current+1) & MASK;}
       inline size_t DSG::RingBuffer::make_pow_2(size_t number){
           return pow(2, ceil(log(number)/log(2)));
       }
//implementation
DSG:: RingBuffer::RingBuffer():Buffer(0),_read(0),_write(0),_count(0),MASK(0){}
DSG:: RingBuffer::RingBuffer(const size_t size):Buffer(make_pow_2(size)),_read(0),_write(0),_count(0){
       MASK = this->_size-1;
}
DSG:: RingBuffer::RingBuffer(RingBuffer& buffer):Buffer(buffer){
       _write.store(buffer._write.load(std::memory_order_acquire));
       _read.store(buffer._read.load(std::memory_order_acquire));
       _count = buffer._count;
       MASK = buffer._size-1;
}
DSG:: RingBuffer& DSG:: RingBuffer::operator=(RingBuffer& buffer){
       Buffer::operator=(buffer);
       _write.store(buffer._write.load(std::memory_order_acquire));
       _read.store(buffer._read.load(std::memory_order_acquire));
       _count = buffer._count;
       MASK = buffer._size-1;
       return *this;
}
DSG:: RingBuffer::~RingBuffer(){Flush();}

