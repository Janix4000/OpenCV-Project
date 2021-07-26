from API.SensorManager.Requests.smHttpRequests import *
from API.SensorManager.Definitions.smEndpoints import *
from Debug.Console import log


# tested
def get_installation_history_contractors(contractor_id):
    url = history_endpoint + 'contractors/' + str(contractor_id)
    log(url)
    resp = get_url(url)
    return resp


# TODO dowiedziec sie co robi ten request
def get_installations_history(installation_id):
    url = history_endpoint + 'installations/' + str(installation_id)
    log(url)
    resp = get_url(url)
    return resp


# TODO dowiedziec sie co robi ten request
def get_installations_history_last(installation_id):
    url = history_endpoint + 'installations/' + str(installation_id) + '/last'
    log(url)
    resp = get_url(url)
    return resp


# tested
def get_installation_history_sensor(sensor_id):
    url = history_endpoint + '/sensors/' + str(sensor_id)
    log(url)
    resp = get_url(url)
    return resp


if __name__ == "__main__":
    # data = get_installation_history_contractors(1)
    # print(data)
    # data = get_installations_history(128)
    # print(data)
    # data = get_installations_history_last(128)
    # print(data)
    # data = get_installation_history_sensor(789)
    # print(data)
    pass
