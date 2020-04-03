#-*Kakao 검색 API*-
import requests
import json

def search():
    url = "https://dapi.kakao.com/v2/search/web"

    headers = {
        'Authorization': 'KakaoAK 543cf556f6b9110873966a8016a61f52'
            }

    data = {
        'query':'코로나19',
        'sort':'recency' 
        }

    response = requests.get(url=url, headers=headers, data=data)
    print("status_code:", response.status_code)
    print("json_data:", response.json())

    return

def search_mv():
    url = "https://dapi.kakao.com/v2/search/vclip"

    headers = {
        'Authorization': 'KakaoAK 543cf556f6b9110873966a8016a61f52'
            }

    data = {
        'query':'AOA',
        'sort':'recency' 
        }

    response = requests.get(url=url, headers=headers, data=data)
    print("status_code:", response.status_code)
    print("json_data:", response.json())


def search_im():
    url = "https://dapi.kakao.com/v2/search/image"

    headers = {
        'Authorization': 'KakaoAK 543cf556f6b9110873966a8016a61f52'
            }

    data = {
        'query':'설현',
        'sort':'accuracy' 
        }

    response = requests.get(url=url, headers=headers, data=data)
    print("status_code:", response.status_code)
    print("json_data:", response.json())


def search_bl():
    url = "https://dapi.kakao.com/v2/search/blog"

    headers = {
        'Authorization': 'KakaoAK 543cf556f6b9110873966a8016a61f52'
            }

    data = {
        'query':'설현',
        'sort':'accuracy' 
        }

    response = requests.get(url=url, headers=headers, data=data)
    print("status_code:", response.status_code)
    print("json_data:", response.json())


def search_tip():
    url = "https://dapi.kakao.com/v2/search/tip"

    headers = {
        'Authorization': 'KakaoAK 543cf556f6b9110873966a8016a61f52'
            }

    data = {
        'query':'카카오톡',
        'sort':'accuracy' 
        }

    response = requests.get(url=url, headers=headers, data=data)
    print("status_code:", response.status_code)
    print("json_data:", response.json())


def search_book():
    url = "https://dapi.kakao.com/v3/search/book"

    headers = {
        'Authorization': 'KakaoAK b27cb1700577646f7e812007693fb00b'
            }

    data = {
        'query':'미운오리 새끼',
        'sort':'accuracy',
        'target':'title' 
        }

    response = requests.get(url=url, headers=headers, data=data)
    print("status_code:", response.status_code)
    print("json_data:", response.json())



if __name__ == '__main__':
    #search_mv()
    #search()
    search()