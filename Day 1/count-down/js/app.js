const endDate="20 July 2023 10:00 PM";

document.getElementById('end-date').innerText=endDate;
const inputs=document.querySelectorAll('input');

function clock() {
    const end=new Date(endDate)
    const now=new Date()
    const diff=(end-now)/1000; //milisecond to second
    if (diff < 0) return;

    inputs[0].value = Math.floor(diff / 60 / 60 / 24);
    inputs[1].value = Math.floor(diff / 60/ 60) % 24;
    inputs[2].value = Math.floor(diff / 60) % 60;
    inputs[3].value = Math.floor(diff) % 60;

}

clock();

setInterval(
    () => {
        clock()
    },
    1000
)


/*
 *  1day=24hr
    1hr=60min
    1min=60sec
 */