const buttons =document.querySelectorAll('.buttons')
const body=document.querySelector('body')

buttons.forEach((button)=>{
    button.addEventListener('click',(e)=>{
        body.style.backgroundColor=e.target.id;
    })
})

