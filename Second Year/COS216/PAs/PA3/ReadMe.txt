How to use:

	The website defaults to log in page first where a user can log in and go to trending.php.
	The user has a link from log in to go to signup.php where they can sign up.
	Once they sign up they are directed back to login where they can now log in as they are signed up.

	I have coded a basic log in (Not according to PA4 spec standard) but it does work and will help
	in testing the flow of the website. I asked Mr. Singh and he confirmed it was okay to leave it in
	despite not being up to spec 4 code.
	
	API use:
	the platform will not return any values unless the wild card is used as the title as stated in the spec,

		a. Returns success but with no data as no title wild card was used to get back a sample of games
			{
    				"key": "c599f6bd712e02a8easdfasdf2e56357f00f013e",
    				"type": "info",
    				"return": "*"
			}

		b. Returns success and a list of games with only title and score attributes
			{
    				"key": "c599f6bd712e02a8easdfasdf2e56357f00f013e",
    				"type": "info",
    				"return": ["title", "score"],
				"title" : "*"
			}
	
		c. Returns success and a list of games with all attributes
			{
    				"key": "c599f6bd712e02a8easdfasdf2e56357f00f013e",
    				"type": "info",
    				"return": "*",
				"title" : "*"
			}

	Searching the api will result in a local search first, then if it is not found locally it is queried for the game form external source
	to then be appended to the current data and a search is conducted again for the now existing game.
	

Default Logins:

	name 		=>	root
	surname		=>	root
	email		=>	root@root.com
	password	=>	Root#123
	API_key		=>	7f08d8c2a996003767fbe0cb09d89589



Functionality not implimented:
	
	I have implimented everything in the spec to my knowledge and it worked in Post man with a body and via POST.

Explinations:

	Password:
		The password require as guided in the spec, 1x CAP, 1x lowercase, 1x digit, 1x specialchar and must be of min lenght 8.
		This is to make passwords more difficult for a human to guess as it forces a more abstract password to be created by the user.

	Choice of the hashing algorithm:
		md5 was used as blowfish was not allowed. The salt added is the persons email appended to the back of the text password in reverse,
		this used strrev() function to invert the string

	API_Key:
		the API_Key is obtained by md5 hashing the person's email, this ensures that the api jey will always be totally unique and not a random number

	Security:
		The website will refuse and request made with GET despite having a valid body in place with parameters.
		The website also ensures that a SQL injection through the username or password text boxes are only interpreted as text.

	KEY:
		I have coded for this prac, that they key is needed to access the api as a parameter but it will accept
		any key you provide it with.