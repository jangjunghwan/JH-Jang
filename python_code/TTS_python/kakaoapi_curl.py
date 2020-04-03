import pycurl
import re
from StringIO import StringIO

buffer = StringIO()
c = pycurl.Curl()
c.setopt(c.URL, 'https://kakaoi-newtone-openapi.kakao.com/v1/synthesize')
c.setopt(c.POST, True)
c.setopt(c.SSL_VERIFYPEER, False) #?
c.setopt(pycurl.HTTPHEADER, [
    'Content-type: application/xml',
    'Authorization: KakaoAK 9408c07df55ac8b12b740941bb8f005b',
])

#c.setopt(c.HEADERFUNCTION, header_function)
c.perform()
print('Status: %d' % c.getinfo(c.RESPONSE_CODE))
print('TOTAL_TIME: %f' % c.getinfo(c.TOTAL_TIME))
c.close()
body = buffer.getvalue()
print(body)