API_username = "1fc8ad6d55cc8708b435c63d0f40119aa87fc30bbec060fe0959e021c4b01f20"
API_password = "cbeab1e0f88cce42aa53207ab284e1ac4548debec517d478e49fa4d59a550f5b"
API_client_id = "1fc8ad6d55cc8708b435c63d0f40119aa87fc30bbec060fe0959e021c4b01f20"

access_token = "a425a8b4-40d0-4c83-8b42-ae96441c1d78"
refresh_token = "3447882a-f159-47be-83a9-582e3aa46317"
token_type = "bearer"
'''{
  "access_token": "363c0c2e-a68b-46db-a5c1-52687e6cf01c",
  "token_type": "bearer",
  "refresh_token": "d9551cbd-4911-4339-977a-70cccc05a00c",
  "expires_in": 604799,
  "scope": "read write trust"
}
curl -X POST --header 'Content-Type: application/json' --header 'Accept: application/json' 'https://api.1ot.mobi/v1/oauth/token?grant_type=refresh_token&username=1fc8ad6d55cc8708b435c63d0f40119aa87fc30bbec060fe0959e021c4b01f20&client_id=1fc8ad6d55cc8708b435c63d0f40119aa87fc30bbec060fe0959e021c4b01f20&password=cbeab1e0f88cce42aa53207ab284e1ac4548debec517d478e49fa4d59a550f5b&refresh_token=3447882a-f159-47be-83a9-582e3aa46317'
curl -X POST --header 'Content-Type: application/json' --header 'Accept: application/json' 'https://api.1ot.mobi/v1/oauth/token?grant_type=password&username=1fc8ad6d55cc8708b435c63d0f40119aa87fc30bbec060fe0959e021c4b01f20&client_id=1fc8ad6d55cc8708b435c63d0f40119aa87fc30bbec060fe0959e021c4b01f20&password=cbeab1e0f88cce42aa53207ab284e1ac4548debec517d478e49fa4d59a550f5b'
{'access_token': 'a425a8b4-40d0-4c83-8b42-ae96441c1d78', 'refresh_token': '3447882a-f159-47be-83a9-582e3aa46317'}
'''

temp_pass = "cbeab1e0f88cce42aa53207ab284e1ac4548debec517d478e49fa4d59a550f5b"
temp_username = "1fc8ad6d55cc8708b435c63d0f40119aa87fc30bbec060fe0959e021c4b01f20"
credentials_filename = "..\\Config\\credentials.txt"


def read_credentials():
    with open(credentials_filename, 'r') as f:
        data = f.readlines()
    access_token = data[0].replace('\n', '')
    refresh_token = data[1].replace('\n', '')
    return {"access_token": access_token, "refresh_token": refresh_token}


def write_credentials(access_token, refresh_token):
    with open(credentials_filename, 'w') as f:
        f.write(access_token + '\n')
        f.write(refresh_token + '\n')




if __name__ == '__main__':
    print(read_credentials())
    write_credentials(access_token="363c0c2e-a68b-46db-a5c1-52687e6cf01c",
                      refresh_token="d9551cbd-4911-4339-977a-70cccc05a00c")
    print(read_credentials())
