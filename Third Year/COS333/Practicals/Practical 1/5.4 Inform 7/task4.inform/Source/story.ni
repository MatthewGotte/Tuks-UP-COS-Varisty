"task4" by Matthew Gotte

[ Instantiate Boxes ]
[ Box One ]
Box One is a container.
Box One is closed.
Bbox One contains South Africa.

[ Box Two ]
Box Two is a container.
Box Two is closed.
Box Two contains France.

[ Instantiate Aquarium ]
The Aquarium is a container.
The aquarium is in Room B.
Paul the Octopus is in The Aquarium.

[ Instantiate  Rooms ]
Room A is a room. 
"You are in Room A and see two boxes. Room B is south".
Room B is a room. 
"You are in Room B, Room A is north. You see an aquarium which contains Paul the Octopus.  place both boxes from Room A in then tell Paul the Octopus which box to open".

[ Initialize Start Location ]
Player is in Room A.

[ Set Proximities ]
Room A is north of Room B.
Room B is south of Room A.

[ Place Boxes ]
Box One is in Room A.
"You can see Box One with a South African flag on it".
Box Two is in Room A.
"You can see Box Two with a French flag on it".

[ logic ]
Every turn: If (Player is in Room A and (Player is holding Box One or Player is holding Box Two)),
say "Go south to Room B".

Every turn : If (Box One is in The Aquarium and Box Two is not in The Aquarium),
say "Waiting for Box Two...".

Every turn : If (Box Two is in The Aquarium and Box One is not in The Aquarium),
say "Waiting for Box One... ".

yourself can be done.

Every turn: if (Box One is in The Aquarium and Box Two is in The Aquarium), 
	if (yourself is done),
		say "Paul the Octopus opened Box One, South Africa will win!".
		
Every turn: if (Box One is in The Aquarium and Box Two is in The Aquarium), 
	if (yourself is not done),
		say "Paul the Octopus opened Box One, France will win!".



