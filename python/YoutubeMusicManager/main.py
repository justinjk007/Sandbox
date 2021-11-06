import sys
from ytmusicapi import YTMusic
ytmusic = YTMusic('headers_auth.json')

## automatically add recently added songs to the "All songs" playlist
## so it can be downloaded in one go on the phone

ALL_SONGS_PLAYLIST = 'PLqILQSyq0LeiWwiGHpgI3NO_aNbTpDhoX' #get the playlist ID from the URL
if(len(sys.argv) > 1):
    HOW_MANY_SONGS = int(sys.argv[1]) # use cmd arg if we pass it
else:
    HOW_MANY_SONGS = 4 # how many of the new songs need to be added ?

print("Songs that are going to be added")
recently_added = ytmusic.get_library_upload_songs(HOW_MANY_SONGS,"recently_added")

new_ids_to_be_added = []
for i in range(0,HOW_MANY_SONGS):
    item = recently_added[i]
    new_ids_to_be_added.append(item["videoId"])
    print("\t","Title:",item["title"]," ID:",item["videoId"])

#  https://ytmusicapi.readthedocs.io/en/latest/reference.html#ytmusicapi.YTMusic.add_playlist_items
result = ytmusic.add_playlist_items(ALL_SONGS_PLAYLIST, new_ids_to_be_added , None, False)
print("Status: ", result)
