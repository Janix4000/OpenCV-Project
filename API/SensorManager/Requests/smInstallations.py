# from API import get_url, patch_url, post_url
from Debug.Console import log
# from API import installations_endpoint
from API.SensorManager.Requests.smHttpRequests import *
from API.SensorManager.Definitions.smEndpoints import *

# tested
# TODO add SMQL language
def get_installations():
    url = installations_endpoint
    log(url)
    resp = get_url(url)
    return resp


def get_installations_smql(smql_query):
    url = installations_endpoint + smql_query
    log(url)
    resp = get_url(url)
    return resp


# tested
def get_installation(installation_id):
    url = installations_endpoint + '/' + str(installation_id)
    log(url)
    resp = get_url(url)
    return resp


# to test
def update_installation_alternative_address(installation_id, alt_adr_1, alt_adr_2):
    # TODO
    #   '''/installations/{id}/address
    #   Update Alt Address'''
    pass


# tested
def update_installation_factors(installation_id, parameter, factor_a, factor_b, factor_c):
    # TODO przegadac zmiane tego, bo sensory tez powinny miec statusy, a nie tylko instalacje
    url = installations_endpoint + '/' + str(installation_id) + '/factors/' + parameter
    request_dict = {"A": factor_a, "B": factor_b, "C": factor_c}
    log(url, request_dict)
    resp = patch_url(url, request_dict)
    return resp


# tested
def update_installation_status(installation_id, status):
    # TODO przegadac zmiane tego, bo sensory tez powinny miec statusy, a nie tylko instalacje
    url = installations_endpoint + '/' + str(installation_id) + '/status'
    request_dict = {"status": status}
    log(url, request_dict)
    resp = patch_url(url, request_dict)
    return resp


# TODO dopisac reszte
def update_installation_suspend(installation_id, start_time, reason, end_time, mearuement_types):
    '''{
  "endTime": "2020-05-03T15:29:06.261Z",
  "measurementsTypes": [
    "pressure"
  ],
  "reason": "string",
  "startTime": "2020-05-03T15:29:06.261Z"
}'''
    # TODO przegadac zmiane tego, bo sensory tez powinny miec statusy, a nie tylko instalacje
    url = installations_endpoint + '/' + str(installation_id) + '/status'
    request_dict = {"endTime", end_time}
    log(url, request_dict)
    resp = post_url(url, request_dict)
    return resp


# tested
def update_installation_tags(installation_id, tag_id, value):
    url = installations_endpoint + '/' +str(installation_id) + '/tags/' + str(tag_id)
    request_dict = {"id": tag_id, "value": value}
    log(url, request_dict)
    resp = patch_url(url, request_dict)
    return resp


# TODO dopisac reszte
def update_installation_unsuspend(installation_id):
    '''{
  "endTime": "2020-05-03T15:31:48.913Z",
  "measurementsTypes": [
    "pressure"
  ],
  "reason": "string",
  "startTime": "2020-05-03T15:31:48.913Z"
}'''


# tested
def update_installation_visibility(installation_id, visibility):
    url = installations_endpoint + '/' +str(installation_id) + '/visibility'
    request_dict = {"visible": visibility}
    log(url, request_dict)
    resp = patch_url(url, request_dict)
    return resp


if __name__ == "__main__":
    test_installation = 395
    # data = get_installations()
    # print(data)

    data = get_installation(test_installation)
    print(data)

    # update_installation_factors(test_installation, 'temperature', 0, 1, 0)
    #
    # update_installation_status(test_installation, status_prototype)

    # update_installation_tags(test_installation, installation_tag_needs_replacement, False)

    # update_installation_visibility(test_installation, False)

