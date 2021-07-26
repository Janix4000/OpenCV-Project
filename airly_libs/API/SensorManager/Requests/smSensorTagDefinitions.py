from API.SensorManager.Requests.smHttpRequests import *
from API.SensorManager.Definitions.smEndpoints import *
from Debug.Console import log


def get_sensors_tag_definition():
    url = sensors_tag_definitions
    log(url)
    resp = get_url(url)
    return resp


# TODO do dopisania, na razie brak potrzeby automatyzacji
def update_sensors_tag_definition(tag_id, value):
    pass


if __name__ == "__main__":
    data = get_sensors_tag_definition()
    print(data)

