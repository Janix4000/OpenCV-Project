import requests
from API.Updater.updaterCredentials import updater_api_auth_token


def updater_get_firmware_version(sensor_id):
    base_url = 'http://updater-gsm.airly.eu/'

    url = base_url + 'sensors/' + str(sensor_id)
    # print(url)
    headers = {"Authorization": "Bearer " + updater_api_auth_token}
    try:
        resp = requests.get(url, headers=headers)
        content = resp.json()
    except Exception as e:
        print('updater data error ', e)
        return {}
    return content


if __name__ == '__main__':
    version = updater_get_firmware_version(5635)
    print(version)
