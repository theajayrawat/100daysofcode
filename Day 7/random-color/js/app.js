const getColor = () => {

    const randomNumber = Math.floor(Math.random() * 16777215); //total possible combinations of RGB(255,255,255)=16777215 
    const randomCode = "#" + randomNumber.toString(16); //Convert to hexcode
    document.body.style.backgroundColor = randomCode;

    document.getElementById("color-code").innerText = randomCode; // Display Hex Code 

    navigator.clipboard.writeText(randomCode) //copy to clipboard
}

//event call
document.getElementById("btn").addEventListener(
    "click",
    getColor
)


// init call
getColor();