import requests
import json

url = "https://kapi.kakao.com/v1/api/talk/profile"

headers = {
    'Content-Type': 'application/xml',
    'Authorization': 'KakaoAK 9408c07df55ac8b12b740941bb8f005b'
}
data = {
	'speak':{
		'voice name' : 'MAN_DIALOG_BRIGHT'
			}
		}

response = requests.get(url=url, 
	headers=headers, 
	data=data)

print("status_code:", response.status_code)
print("data:", response.json)