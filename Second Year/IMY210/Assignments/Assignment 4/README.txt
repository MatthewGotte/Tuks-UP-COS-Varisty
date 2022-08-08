u20734621 - Matthew Gotte

==============

1, data.json holds all data used by/written by the API.
2, My API can accept a .json file via post to be appended to the list.

	In order to use this I have included test_file.json.

	BEFORE uploading the file please move it out of the directory of the server as the code will
	upload, use then delete the file from the server. So, remove it, then upload it from another 
	directory for eg. >Desktop otherwise the file will upload and work 100% but then the file will
	be deleted as the only copy would be in the server directory. ( this is mymicing a standard user upload ).

3, My ID is auto generated. It moves sequentially from the last known ID (like AUTO_INC). If a item is deleted
   that ID becomes unusable and numbering will work similarly to a SQL database with auto inc.

==============
