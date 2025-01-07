const form=document.querySelector('form')

form.addEventListener('submit',(e)=>{
    e.preventDefault()

   const height= parseInt(document.querySelector('#height').value)
   const weight=parseInt(document.querySelector('#weight').value)
   const results=document.querySelector('.results')
   if(height=='' || height<=0 || isNaN(height))
   {
      results.innerHTML=`Enter a valid height ${height}`
   }
   else if(weight=='' || weight<=0 || isNaN(weight))
    {
       results.innerHTML=`Enter a valid weight ${weight}`
    }
    else{
        const suggestion=document.querySelector('.suggestion')
        const bmi=(weight/((height*height)/10000)).toFixed(2)

        results.innerHTML=`<span>${bmi}</span>`

        if(bmi<18.6)
            suggestion.innerHTML="You have to increase your weight"
        else if(18.6>=bmi<=24.9)
            suggestion.innerHTML="your weight is good hurray!"
        else if(bmi>24.9)
            suggestion.innerHTML="Your have to decrease your weight"
    }
})
