
import requests
headers = {
    'Authorization': 'KakaoAK 9408c07df55ac8b12b740941bb8f005b',
    'Content-Type': 'application/xml'
}
r = requests.post('https://kakaoi-newtone-openapi.kakao.com/v1/synthesize',  json=[], headers=headers)
print(r.elapsed.total_seconds())
print(r.headers)
print(r.json())