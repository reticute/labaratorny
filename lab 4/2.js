'use strict'

function max(arr) {
    let best = -Infinity
    for (const row of arr) {
        for (const x of row) {
            if (x > best) best = x
        }
    }
    return best
}

const m = max([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
console.log(m)