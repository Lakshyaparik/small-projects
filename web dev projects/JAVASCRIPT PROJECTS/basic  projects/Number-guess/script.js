const randomNumber=(parseInt(Math.random()*100+1));
const submit=document.querySelector('#subt')
const userinput=document.querySelector('#guessfeild')
const startover=document.querySelector('.resultparas')
const loworhi=document.querySelector('.loworhi')
const guessSlot=document.querySelector('.guesses')
const remaning=document.querySelector('.lastresult')
const form=document.querySelector('.form')
const p=document.createElement('p')
const hint=document.querySelector('.hint')
const start=document.querySelector('.start')
let prevguess=[]
let numguess=1
let playgame=true;

newgame()

function startgame()
{
start.style.classList.add('.hidden')
if(playgame)
{
    submit.addEventListener('click',(e)=>{
        e.preventDefault()
        const guess=parseInt(userinput.value) 
        userinput.value=' '
        validateguess(guess)
    })
}
}
function validateguess(guess)
{
    if(isNaN(guess)|| guess<=0 || guess>100)
    {
        displaymessage(`Your number is not valid ${guess}`)
    }
    else
    {
        checkguess(guess)
    }
}
function checkguess(guess)
{
    if(guess==randomNumber)
    {
        displaymessage(`Hurray your guess is right! ${guess}`)
        endgame()
    }
    if(guess<randomNumber)
    {
        userhint(`hint: Your number is too short`)
    }
    if(guess>randomNumber)
    {
        userhint(`hint: Your number is too high`)
    }
    else if(numguess==11)
    {
        displaymessage(`Your have 0 turns! better luck next time`)
        endgame()
    }
    else
    {
        operate(guess)
    }
}
function operate(guess)
{
    prevguess.push(guess)
    console.log(prevguess);
    numguess++
    displayguess(guess)
}
function displayguess(guess)
{
    guessSlot.innerHTML=prevguess.join(" ")
    remaning.innerHTML=11-numguess
}
function displaymessage(guess)
{
    loworhi.innerHTML=guess
}
function userhint(output)
{
    hint.innerHTML=output
}
function endgame()
{
    numguess=1;
    prevguess=" "
    playgame=false
    newgame()
}
function newgame()
{
    startgame()
}

