from API.SensorManager.Config.smCredentials import sensor_manager_api_auth_token
import requests
from Debug.Console import log, log_http

headers = {"Authorization": "Bearer " + sensor_manager_api_auth_token}


def get_url(url):
    resp = requests.get(url, headers=headers)
    log_http(resp)
    content = resp.json()
    return content


def patch_url(url, data_dict):
    resp = requests.patch(url, json=data_dict, headers=headers)
    log(resp)
    return resp


def post_url(url, param):
    pass
