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

    brampton_dates_last = brampton_dates[-1].split("~")
    mississauga_dates_last = mississauga_dates[-1].split("~")

    brampton_expected_dates = '2024-03-31'
    mississauga_expected_dates = '2024-03-31'
    changed = False
    if(brampton_expected_dates != brampton_dates_last[-2]):
        changed = True
    if(mississauga_expected_dates != mississauga_dates_last[-2]):
        changed = True

    if(changed):
        return f'No changes,\n\n Mississauga: {mississauga_dates_last[-2]}\n\n Brampton: {brampton_dates_last[-2]}'
    else:
        return f'Dates haven\'t changed,\n\n Mississauga: {mississauga_dates_last[-2]}\n\n Brampton: {brampton_dates_last[-2]}'

if __name__ == "__main__":
    print(check())
