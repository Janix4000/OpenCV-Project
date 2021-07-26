from API.OneoT.Config.OneOTcredentials import access_token
import requests
from Debug.Console import log, log_http

headers = {"Authorization": "Bearer " + access_token}


def get_url(url):
    resp = requests.get(url, headers=headers)
    log_http(resp)
    print(resp.content)
    content = resp.json()
    return content


def patch_url(url, data_dict):
    resp = requests.patch(url, json=data_dict, headers=headers)
    log(resp)
    return resp


def post_url(url, data_dict):
    resp = requests.post(url, json=data_dict, headers=headers)
    log(resp)
    return resp