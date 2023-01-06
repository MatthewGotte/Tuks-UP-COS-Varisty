prompt = function () {
    return db + " $ ";
}

function insertPoints(dbName, colName, xcount, ycount) {

    db = db.getSiblingDB(dbName)
    let x = parseFloat(xcount)
    let y = parseFloat(ycount)

    for (let i = 0; i < x; i++) {
        for (let t = 0; t < y; t++) {
            db.getCollection(colName).insert({ "x": `${i}`, 'y': `${t}` })
        }
    }

    // db.getCollection(colName).insert({ "x": `${xcount}`, 'y': `${ycount}` })

}

function findNearest(dbName, colName, xval, yval) {
    db = db.getSiblingDB(dbName)
    let obj = db.getCollection(colName).find()
    let max = 0.0
    let maxObj = {}
    let x1 = parseFloat(xval)
    let y1 = parseFloat(yval)

    if (obj.length() > 0) {
        maxObj = obj[0]
        for (let i = 0; i < obj.length(); i++) {
            var element = obj[i]

            let x2 = parseFloat(element["x"])
            let y2 = parseFloat(element["y"])

            let temp1 = Math.pow(x2 - x1, 2)
            let temp2 = Math.pow(y2 - y1, 2)

            let temp3 = Math.sqrt(temp1 + temp2)


            if (temp3 > max) {

                max = temp3
                maxObj = obj[i]

            }
        }
        return (maxObj)

    }
}

function updateYVals(dbName, colName, threshold, incr) {

    db = db.getSiblingDB(dbName)
    let obj = db.getCollection(colName).find()
    let t = parseFloat(threshold)
    if (obj.length() > 0) {
        for (let i = 0; i < obj.length(); i++) {
            var element = obj[i]
            let y = parseFloat(element["y"])
            if (y > t) {
                y = y + incr
                db.getCollection(colName).findOneAndUpdate({
                    'y': element["y"]
                }, {
                    $set: {
                        'y': y
                    }
                })
            }
        }

    }

}

function removeIfYless(dbName, colName, threshold) {
    db = db.getSiblingDB(dbName)
    let obj = db.getCollection(colName).find()
    let t = parseFloat(threshold)
    if (obj.length() > 0) {
        for (let i = 0; i < obj.length(); i++) {
            var element = obj[i]
            let y = parseFloat(element["y"])
            if (y < t) {

                db.getCollection(colName).findOneAndDelete({
                    'y': element["y"]
                })
            }
        }

    }
}

function allStatesPopulation(dbName, colName) {
    db = db.getSiblingDB(dbName)
    let obj = db.getCollection(colName).aggregate([
        {
            "$group": {
                _id: '$state',
                population: { $sum: "$pop" }
            }

        },
        {
            $sort: { _id: 1 }
        },
    ])

    return (obj)

}

function oneStatePopulation(dbName, colName, stateName) {
    db = db.getSiblingDB(dbName)
    let obj = db.getCollection(colName).aggregate([
        { $match: { state: stateName } },
        {
            "$group": {
                _id: '$state',
                population: { $sum: "$pop" }
            }

        },
        {
            $sort: { _id: 1 }
        },
    ])

    return (obj)

}


function allStatesPopulationMR(dbName, colName) {
    db = db.getSiblingDB(dbName)
    var mapFunction1 = function () {
        emit(this.state, this.pop)
    };
    var reduceFunction1 = function (stateId, statePop) {
        return Array.sum(statePop)
    };
    db.getCollection(colName).mapReduce(
        mapFunction1
        ,
        reduceFunction1
        ,
        {
            out: 'states_population'
        }

    )

    return db.states_population.find()
}

function placesInGrid(dbName, colName, lat1, lat2, lon1, lon2) {
    db = db.getSiblingDB(dbName)
    let obj = db.getCollection(colName).find()
    let toReturn = []
    for(let i =0; i<obj.length();i++){
        let element = obj[i]

        if(lat1<element.loc[0] && element.loc[0]<lat2 && lon1<element.loc[1] && element.loc[1]<lon2) toReturn.push(element)

    }

    return toReturn
}