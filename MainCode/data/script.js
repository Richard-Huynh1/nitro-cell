function forward(){

}

function backward(){
    
}

function left(){
    
}

function right(){
    
}

function Uleft(){
    
}

function Uright(){
    
}

function Dleft(){
    
}

function Dright(){
    
}

function checkMinMaxFunction(value){
  const minValue = 0;
  const maxValue = 255;
  let trueValue = parseInt(value);

  if (isNaN(trueValue)) {
    trueValue = minValue;
  } else if (trueValue < minValue) {
    trueValue = minValue;
  } else if (trueValue > maxValue) {
    trueValue = maxValue;
  }
  return trueValue;
}

const rangeSlider = document.getElementById('myRange');
const numberInput = document.getElementById('number-input');

rangeSlider.addEventListener('input', function() {
  numberInput.value = checkMinMaxFunction(numberInput.value);
  console.log('Range slider value:', rangeSlider.value);
});

numberInput.addEventListener('input', function() {
  numberInput.value = checkMinMaxFunction(numberInput.value);
  rangeSlider.value = checkMinMaxFunction(numberInput.value);
  console.log('Number input value:', numberInput.value);
});