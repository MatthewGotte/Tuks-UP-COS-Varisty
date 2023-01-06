//u20734621 - Matthew Gotte

//Task 1:
function insertPoints(dbName, colName, xcount, ycount) {

	let col = db.getSiblingDB(dbName).getCollection(colName);
	for (let xval = 1; xval <= xcount; xval++) { //for each
        for (let yval = 1; yval <= ycount; yval++) {
			col.insert({ xval : (xval * 2), yval : (yval * 2)}); //produces 
		}
    }

}

function findNearest(dbName, colName, xval, yval) { 

    var col = db.getSiblingDB(dbName).getCollection(colName);

    var near = null;
    var hit = null;

    col.find().forEach(

        function (doc) {

            var a = xval - doc.xval;
            a *= a;
            var b = yval - doc.yval;
            b *= b;
            var c = Math.sqrt(a + b);

            if (near == null) {
                near = c;
                hit = doc; 
            } else {
                if (near > c) {
                    near = c;
                    hit = doc; 
                }
            }
        }

    ); 

    print(hit);
}

function updateYVals(dbName, colName, threshold, incr) {   

    var col = db.getSiblingDB(dbName).getCollection(colName); 

    col.updateMany(
        { 
            yval : { 
                $gt : threshold 
            }
        }, {
            $inc: { 
                yval : incr 
            }
	    }
    );

}

function removalIfYless(dbName, colName, threshold) {  

    var col = db.getSiblingDB(dbName).getCollection(colName); 

	col.deleteMany(
        { 
            yval : { 
                $lt : threshold 
            } 
        } 
    );

}

// insertPoints("prac8db", "Cartesian", 5, 5)
// findNearest("prac8db", "Cartesian", 5, 7)
// updateYVals("prac8db", "Cartesian", 2, 10)
// removalIfYless("prac8db", "Cartesian", 4)

//Task 2:

function allStatesPopulation(dbName, colName) {

    db = db.getSiblingDB(dbName).getCollection(colName);

    let obj = db.aggregate([
        {
            "$group": {
                _id: '$state',
                population: { 
                    $sum: "$pop"
                }
            }

        },
        {
            $sort: { 
                _id: 1 
            }
        },
    ])

    print(obj)

}


function oneStatePopulation(dbName, colName, stateName) {

    db = db.getSiblingDB(dbName).getCollection(colName);

    let obj = db.aggregate([
        { 
            $match: { 
                state: stateName 
            } 
        },
        {
            "$group": {
                _id: '$state',
                population: { 
                    $sum: "$pop" 
                }
            }

        },
        {
            $sort: { 
                _id: 1 
            }
        },
    ])

    print(obj)

}

function allStatesPopulationMR(dbName, colName) {

    db = db.getSiblingDB(dbName).getCollection(colName);

    var mapFunction1 = function () {
        emit(this.state, this.pop)
    };

    var reduceFunction1 = function (stateId, statePop) {
        return Array.sum(statePop)
    };

    db.mapReduce(
        mapFunction1, reduceFunction1, {
            out: 'states_population'
        }
    )

    print(db.states_population.find());

}

function placesInGrid(dbName, colName, lat1, lat2, lon1, lon2) {

    db = db.getSiblingDB(dbName).getCollection(colName)
    let output = []

    let obj = db.find().forEach((element) => {
        if (lat1 < element.loc[0] && element.loc[0] < lat2 && lon1 < element.loc[1] && element.loc[1] < lon2) 
            output.push(element)
    })

    output.forEach(el => {
        print(el);
    });

}