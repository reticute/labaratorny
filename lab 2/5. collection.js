'use strict'

const caller =[
    {name: 'Ilaria Panciroli', phone: '+380508523252'},
    {name: 'Manoel Medeiros', phone: '+380950684572'},
    {name: 'Cheryl Sanders', phone: '+380790245252'},
    {name: 'Sam Dunne', phone: '+380758308738'},
]

function findPhoneByName(name) {
    for (let i = 0; i < caller.length; i++) {
        if (caller[i].name === name) {
            return caller[i].phone;
        }
    }
    return undefined;
}

console.log(findPhoneByName('Sam Dunne'));
console.log(findPhoneByName('John Egbert'));

// -----

const caller2 = {
    'Ilaria Panciroli': '+380508523252',
    'Manoel Medeiros': '+380950684572',
    'Cheryl Sanders': '+380790245252',
    'Sam Dunne': '+380758308738',
}

function findPhoneByName2(name) {
    return caller2[name];
}

console.log(findPhoneByName2('Ilaria Panciroli'));
console.log(findPhoneByName2('Dave Strider'));