const clock=document.getElementsByClassName('clock')[0]

setInterval(() => {
    const date=new Date()
    clock.innerHTML=date.toLocaleTimeString()
}, 1000);
