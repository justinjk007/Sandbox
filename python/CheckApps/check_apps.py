import requests
import secret

def check():
    url = secret.url

    # brampton
    params1 = {'gofor': 'show_apt_date', 'location': '4', 'service_type': 'OCI' }
    # Mississauga
    params2 = {'gofor': 'show_apt_date', 'location': '15', 'service_type': 'OCI' }
    check_brampton = requests.post(url, params=params1)
    check_mississauga = requests.post(url, params=params2)
    brampton_dates = check_brampton.text.split(",")
    mississauga_dates = check_mississauga.text.split(",")

    # print("Brampton data:")
    # print(brampton_dates[-1])
    # print("Mississauga data:")
    # print(mississauga_dates[-1])

    brampton_expected_dates = '31-03-2024~2024-02-15~OCI~2024-02-15~2024-03-31~'
    mississauga_expected_dates = '31-03-2024~2024-02-15~OCI~2024-02-16~2024-03-31~'

    if(brampton_expected_dates != brampton_dates[-1]):
        print(f'Brampton dates changed: {brampton_dates[-1]}')
        return f'Brampton dates changed: {brampton_dates[-1]}'

    if(mississauga_expected_dates != mississauga_dates[-1]):
        print(f'Mississauga dates changed: {mississauga_dates[-1]}')
        return f'Mississauga dates changed: {mississauga_dates[-1]}'


    print(f'Dates haven\'t changed,\n\n Mississauga:{mississauga_dates[-1]}\n\n Brampton:{brampton_dates[-1]}')
    return f'Dates haven\'t changed,\n\n Mississauga:{mississauga_dates[-1]}\n\n Brampton:{brampton_dates[-1]}'
