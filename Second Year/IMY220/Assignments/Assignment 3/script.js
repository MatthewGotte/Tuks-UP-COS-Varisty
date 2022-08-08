const quizzes = [
	{quiz: "The Cats Quiz", creator: "I_Make_Quizzes", score: 74},
	{quiz: "Do You Know Marvel?", creator: "QuizLover55", score: 48},
	{quiz: "Do You Know Disney?", creator: "QuizLover55", score: 78},
	{quiz: "The Dogs Quiz", creator: "I_Make_Quizzes", score: 45},
	{quiz: "Random Trivia Quiz", creator: "ThatTrviaMastr", score: 88},
	{quiz: "Anime Trivia Quiz", creator: "ThatTrviaMastr", score: 68},
	{quiz: "The Movies Quiz", creator: "I_Make_Quizzes", score: 80},
	{quiz: "Do You Know Your Memes?", creator: "QuizLover55", score: 75},
	{quiz: "Game Trivia Quiz", creator: "ThatTrviaMastr", score: 62},
];

const handler = new QuizHandler(quizzes);

console.group("1. getScoresAbove()");
console.log(".getScoresAbove(40)");
let sco = handler.getScoresAbove(40);
console.log(sco);
console.log(".getScoresAbove(70)");
sco = handler.getScoresAbove(70);
console.log(sco);
console.log(".getScoresAbove(80)");
sco = handler.getScoresAbove(80);
console.log(sco);
console.groupEnd();


console.group("2. getUniqueCreators()");
console.log(".getUniqueCreators()");
const uniq = handler.getUniqueCreator();
console.log(uniq);
console.groupEnd();


console.group("3. getDescription()");
console.log(".getDescription() no arguments");
let desc = handler.getDescriptions();
console.log(desc);
console.log(".getDescription() 1 argument");
desc = handler.getDescriptions(quizzes[0]);
console.log(desc);
console.log(".getDescription() 5 arguments");
desc = handler.getDescriptions(quizzes[0], quizzes[2], quizzes[4], quizzes[1], quizzes[3]);
console.log(desc);
console.groupEnd();
