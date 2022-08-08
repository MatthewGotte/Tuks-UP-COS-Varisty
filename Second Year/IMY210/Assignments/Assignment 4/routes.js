var router = (app, fs) => {
    //functions here
    data_file = 'data.json';
    
    app.get('/data', (request, respond) => {
        //GET
        fs.readFile(data_file, (error, rdata) => {
            if (error)
                throw error;
            try {
                respond.send(JSON.parse(rdata));
            } catch (e) {
                respond.send('');
            }
        });
    });

    app.get('/data/:id', (request, respond) => {
        var temp = request.params['id'];
        fs.readFile(data_file, (error, rdata) => {
            if (error)
                throw error;
            json = JSON.parse(rdata);
            output = json.filter(function(target){
                return (target.id == temp);
            });
            respond.send(output);
        });
    });

    app.post('/data', (request, respond) => {
        fs.readFile(data_file, (error, rdata) => {
            if (error)
                throw error;
            var json;
            try {
                var len = Object.keys(JSON.parse(rdata)).length;
                json = JSON.parse(rdata); 
                var newID = json[len - 1].id;   //Get id value of last item
                newID++;                        //Inc. last id by 1 for the new id value
                //console.log(newID);
                var newItem = {'id': newID};
                newItem = {...newItem, ...request.body};    //spread operator to join the object with the id
                json[len] = newItem;
            } catch (e) {
                var newID = 1;   //set value id for first item
                var newItem = {'id': newID};
                newItem = {...newItem, ...request.body};    //spread operator to join the object with the id
                json = newItem;
            }
            var output = JSON.stringify(json);
            fs.writeFile(data_file, output, (error) => {
                if (error)
                    throw error;
            });
            respond.send(json);
        });
    });

    app.put('/data/:id', (request, respond) => {
        var temp = request.params['id'];
        fs.readFile(data_file, (error, rdata) => {
            if (error)
                throw error;
                var len = Object.keys(JSON.parse(rdata)).length;
                var json = JSON.parse(rdata);
                for (var i = 0; i < len; i++) {
                    if (json[i].id == temp) {
                        //console.log(json[i].name);
                        var newItem = {'id': parseInt(temp)};
                        newItem = {...newItem, ...request.body};    //spread operator to join the object with the id
                        //json = newItem;
                        json[i] = newItem;
                    }
                }
                var output = JSON.stringify(json);
                fs.writeFile(data_file, output, (error) => {
                    if (error)
                        throw error;
                });
                respond.send(json);
            });
    });

    app.delete('/data/:id', (request, respond) => {
        var temp = request.params['id'];
        fs.readFile(data_file, (error, rdata) => {
            if (error)
                throw error;
            json = JSON.parse(rdata);
            filtered = json.filter(function(target){
                return (target.id != temp);
            });
            var output = JSON.stringify(filtered);
            fs.writeFile(data_file, output, (error) => {
                if (error)
                    throw error;
            });
            respond.send(filtered);
        });
    });

}
module.exports = router;