from API.OneoT.Config.OneOTcredentials import *
from API.OneoT.Definitions.OneOTEndpoints import *
from API.OneoT.Requests.OneOTHttpRequests import *
import json

def get_access_token():
    url = endpoint_get_oauth_token
    log_http(url)
    grant_type = "password"
    data_url = "grant_type={}&username={}&client_id={}&password={}".format(grant_type, API_username, API_client_id,
                                                                           API_password)
    url = url + data_url
    resp = post_url(url, data_dict={})
    return resp


def refresh_access_token():
    url = endpoint_get_oauth_token
    log_http(url)
    grant_type = "password"
    data_url = "grant_type={}&username={}&client_id={}&password={}".format(grant_type, API_username, API_client_id,
                                                                           API_password)
    url = url + data_url
    resp = post_url(url, data_dict={})
    return resp


def get_credentials(refresh_token=False, get_new_credentials=False):
    if refresh_token:
        data = refresh_access_token().content
        credentials_data = json.loads(data)
        write_credentials(access_token=credentials_data['access_token'],
                          refresh_token=credentials_data['refresh_token'])
    if get_new_credentials:
        data = get_access_token().content
        credentials_data = json.loads(data)
        write_credentials(access_token=credentials_data['access_token'],
                          refresh_token=credentials_data['refresh_token'])
    credentials = read_credentials()
    return credentials

if __name__ == '__main__':
    data = get_credentials(get_new_credentials=True)
    print(data)