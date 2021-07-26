from API.SensorManager.Definitions.smEndpoints import *
from API.SensorManager.Requests.smHttpRequests import *
from Debug.Console import log


def get_installations_tag_definition():
    url = installation_tag_definitions
    log(url)
    resp = get_url(url)
    return resp


# TODO do dopisania, na razie brak potrzeby automatyzacji
def update_installations_tag_definition(tag_id, value):
    pass


if __name__ == "__main__":
    data = get_installations_tag_definition()
    print(data)