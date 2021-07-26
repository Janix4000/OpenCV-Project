from API.SensorManager.Requests.smHttpRequests import *
from API.SensorManager.Definitions.smEndpoints import *
from Production.Database.external_db_gas_module_updater import get_gas_unit_gases_dicts
from Debug.Console import log


# TODO add SMQL language
def get_sensors():
    url = sensors_endpoint
    log(url)
    resp = get_url(url)
    return resp


def get_sensors_smql(smql_query):
    url = sensors_endpoint + smql_query
    log(url)
    resp = get_url(url)
    return resp


def get_sensor(sensor_id):
    url = sensors_endpoint + '/' + str(sensor_id)
    log(url)
    resp = get_url(url)
    return resp


# def update_sensor_parameter(sensor_id, parameter, factor_a, factor_b, factor_c):
#     url = sensors_endpoint + '/' + str(sensor_id) + '/factors/' + parameter
#     request_dict = {"A": factor_a, "B": factor_b, "C": factor_c}
#     log(url, request_dict)
#     resp = patch_url(url, request_dict)
#     return resp


def update_sensor_status(sensor_id, status):
    url = sensors_endpoint + '/' + str(sensor_id) + '/status'
    request_dict = {"status": status}
    log(url, request_dict)
    resp = patch_url(url, request_dict)
    return resp


def update_sensor_tag(sensor_id, tag_id, value):
    url = sensors_endpoint + '/' + str(sensor_id) + '/tags/' + str(tag_id)
    request_dict = {"id": tag_id, "value": value}
    log(url, request_dict)
    resp = patch_url(url, request_dict)
    return resp


def update_sensor_measured(sensor_id, measured_list):
    url = measured_endpoint.format(sensor_id)
    request_dict = {"measurementTypes": measured_list}
    log(url, request_dict)
    resp = patch_url(url, request_dict)
    return resp


def update_sensor_parameter(sensor_id, param, parameter_factors):
    url = sensors_endpoint + '/' + str(sensor_id) + '/factors/' + param
    request_dict = parameter_factors
    # print(url)
    log(url, request_dict)
    resp = patch_url(url, request_dict)
    return resp


