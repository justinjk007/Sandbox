import sys
from ytmusicapi import YTMusic
ytmusic = YTMusic('oauth.json')

all_uploaded = ytmusic.get_library_upload_songs(None,"recently_added")

for item in all_uploaded:
    print(f"Deleting: { item['title'] }")
    status = ytmusic.delete_upload_entity(item["entityId"])
    print(f"Finished: { status }")
