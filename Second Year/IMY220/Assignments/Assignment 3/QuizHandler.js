class QuizHandler {
	constructor(q) {
        const quizzes = [...q];
    }

    getScoresAbove(score) {
        return quizzes.filter(quiz => quiz.score > score);
    }

    getUniqueCreator() {
        return quizzes.reduce((val, product) => {
            const quiz = !!val.find((uniqueCreatorName) => (
              uniqueCreatorName.creator === product.creator
            ));
        
            if (!quiz) {
              return [ ...val, product ]
            }
        
            return val;
          }, [])
    }

    getDescriptions(...arg) {
        let arr = [...arg];
        if (arr.length == 0)
            arr = quizzes;
        const output = arr.map(arr => {
            return `${arr.quiz} (created by: ${arr.creator}): ${arr.score}%`;
        });
        return output;
    }
}