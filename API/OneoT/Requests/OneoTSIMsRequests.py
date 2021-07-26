from API.OneoT.Config.OneOTcredentials import *
from API.OneoT.Definitions.OneOTEndpoints import *
from API.OneoT.Requests.OneOTHttpRequests import *


def get_sims():
    """ found
        offset
        total
        sims"""
    url = endpoint_get_sims
    log(url)
    resp = get_url(url)
    return resp


def get_sim_cost(iccid):
    url = endpoint_get_sim_cost + str(iccid)
    log_http(url)
    resp = get_url(url)
    if "SIM not found" in resp.get('error_description', ""):
        raise KeyError
    return resp


def get_sim_diagnostics(iccid):
    url = endpoint_get_diagnostics + str(iccid)
    log_http(url)
    resp = get_url(url)
    print(resp)
    if "SIM not found" in resp.get('error_description', ""):
        raise KeyError
    return resp


def get_sim_sessions(iccid):
    url = endpoint_get_sim_sessions + str(iccid)
    log_http(url)
    resp = get_url(url)
    if "SIM not found" in resp.get('error_description', ""):
        raise KeyError
    return resp


def batch_get_sim_diagnostic(iccid_array):
    pass


if __name__ == '__main__':
    # sims = get_sims()
    # print(sims['offset'])
    # print(sims['total'])
    # print(sims['found'])
    # counter = 0
    # for row in sims['sims']:
    #     counter += 1
    #     print(counter)
    #     print(row)

    # test_iccid = "8944502407183837476"
    test_iccid = "8944502407183837476"
    print("DIAGNOSTICS")
    diagnostics_data = get_sim_diagnostics(test_iccid)
    print(diagnostics_data)

    print("COSTS")
    sim_cost = get_sim_cost(test_iccid)
    print(sim_cost)

    print("SIM SESSIONS")
    sim_sessions = get_sim_sessions(test_iccid)
    print(sim_sessions)