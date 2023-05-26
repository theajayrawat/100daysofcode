const quizData = [{
        question: "Which of the following is a client site language?",
        0: "Java",
        1: "C",
        2: "Python",
        3: "JavaScript",
        correct: "3",
    },
    {
        question: "What does HTML stand for?",
        0: "Hypertext Markup Language",
        1: "Cascading Style Sheet",
        2: "Jason Object Notation",
        3: "Helicopters Terminals Motorboats Lamborginis",
        correct: "0",
    },
    {
        question: "What year was JavaScript launched?",
        0: "1996",
        1: "1995",
        2: "1994",
        3: "none of the above",
        correct: "1",
    },
    {
        question: "What does CSS stands for?",
        0: "Hypertext Markup Language",
        1: "Cascading Style Sheet",
        2: "Jason Object Notation",
        3: "Helicopters Terminals Motorboats Lamborginis",
        correct: "1",
    }
];

let index = 0,
    correct = 0,
    total = quizData.length;
let allInputs = document.querySelectorAll("input[type='radio']")
const loadQuestion = () => {
    if (total === index) {
        return quizEnd()
    }
    reset()
    const data = quizData[index]
    document.getElementById("questionBox").innerHTML = `${index + 1}) ${data.question}`

    for(let i=0;i<4;i++){
        allInputs[i].nextElementSibling.innerText = data[i]
    }
 
}

document.querySelector("#submit").addEventListener("click", submit)

function submit () {
    const data = quizData[index]
    const ans = getAnswer()
    if (ans === data.correct) {
        correct++;
    } 
    index++;
    loadQuestion()
}

const getAnswer = () => {
    let ans;
    allInputs.forEach(
        (inputEl) => {
            if (inputEl.checked) {
                ans= inputEl.value; 
            }
        }
    )
    return ans;
}

const reset = () => {
    allInputs.forEach(
        (inputEl) => {
            inputEl.checked = false;
        }
    )
}

const quizEnd = () => {
    // console.log(document.getElementsByClassName("container"));
    document.getElementsByClassName("container")[0].innerHTML = `
        <div class="col">
            <h3 class="w-100">You've scored is ${correct} / ${total} &#129488</h3>
        </div>
    `
}

loadQuestion(index);

