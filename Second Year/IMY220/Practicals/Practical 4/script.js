class MultipleChecker
{
	constructor() {

	}

	isMultiple = (num, multiplication) => {
		if (num % multiplication === 0)
			return `${num} is a multiple of ${multiplication}.`;
		else
			return `${num} is not a multiple of ${multiplication}.`;
	}

	fillArray = (length, multiplication) => {
		const arr = [];
		for(let i = 0; i < length; i++)
		{
			arr.push((i + 1) * multiplication);
		}//end for
		return `First ${length} multiples of ${multiplication}: ${arr}`;

	}//end function

}//end MultipleChecker


function checkPangram(sentence)
{
	var alphabet = "abcdefghijklmnopqrstuvwxyz";

	// convert to character array
	alphabet = alphabet.split("");

	// convert to lowercase
	sentence = sentence.toLowerCase();

	return alphabet.every(function(element, index)
	{
		return sentence.indexOf(element) > -1;

	});

}//end checkPangram

function checkDifferentVowels(sen) {

	const input = [...sen];
	//input is char array of sen.
	//reduce down all non-vowels.
	const output = [];
	input.reduce((val, target) => {
		//check if in vowels:
		if (vowels.includes(target)) {
			output.push(target);
		}
	}, [])
	//reduce to only duplicates.
	let cut = output.reduce((val, product) => {
		const quiz = !!val.find((uniqueCreatorName) => (
		  uniqueCreatorName === product
		));
	
		if (!quiz) {
		  return [ ...val, product ]
		}
	
		return val;
	  }, [])
	//check length of number of duplicates.
	if (cut.length > 1)
		return `The string ${sen} contains more than one vowel.`;
	else
		return `The string ${sen} does not contain more than one vowel.`;

}


const vowels = ["a", "e", "i", "o", "u"];


const checker = new MultipleChecker();

document.getElementById("checkMultipleBtn").onclick = function()
{
	document.getElementById("multipleResult").innerHTML = checker.isMultiple(document.getElementById("multipleChecker").value, document.getElementById("multiplicationTable1").value);
}

document.getElementById("getmultipleList").onclick = function()
{
	document.getElementById("multipleListResult").innerHTML = checker.fillArray(document.getElementById("multipleList").value, document.getElementById("multiplicationTable2").value);
}

document.getElementById("checkPangram").onclick = function()
{
	document.getElementById("pangramResult").innerHTML = checkPangram(document.getElementById("pangramChecker").value);
}

//add onclick to checkDifferentVowels:
document.getElementById("checkVowel").onclick = function() {
	document.getElementById("vowelResult").innerHTML = checkDifferentVowels(document.getElementById("vowelChecker").value);
}




const a = (x) => {
	return `hello the value is ${x}`;
}