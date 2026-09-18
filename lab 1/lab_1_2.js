const array = [
    true, false, 67, 'hello world', 8.4, -12803, 'JavaScript', 'great', 909,
    -0.15, 413, true, 'totally three words', 'gggg', 300000, 15.9
]

const empty = {number: 0, string: 0, boolean: 0}


for (const item of array) {
    const type = typeof item;
    
   if (type in array) {
    array[type]++
   }
}

console.dir(array)
