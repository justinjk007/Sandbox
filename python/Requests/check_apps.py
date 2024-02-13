import requests

url = 'https://www.blsindia-canada.com/appointmentbls/ajax.php'

# brampton
params1 = {'gofor': 'show_apt_date', 'location': '4', 'service_type': 'OCI' }
# Mississauga
params2 = {'gofor': 'show_apt_date', 'location': '15', 'service_type': 'OCI' }

check_brampton = requests.post(url, params=params1)
check_mississauga = requests.post(url, params=params2)

brampton_dates = check_brampton.text.split(",")
mississauga_dates = check_mississauga.text.split(",")

print("Brampton data:")
print(brampton_dates[-1])
print("Mississauga data:")
print(mississauga_dates[-1])
