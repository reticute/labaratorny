'use strict'

const iface = {
  m1: x => [x],

  m2: function (x, y) {
    return [x, y];
  },

  m3(x, y, z) {
    return [x, y, z];
  }
}

const introspection = (obj) => {
  const result = []

  for (let iface in obj) {
    if (typeof obj[iface] === 'function') {
      result.push([iface, obj[iface].length]);
    }
  }

  return result;
};
console.log(introspection(iface))
