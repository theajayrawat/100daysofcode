// Webpage:https://leetcode.com/problems/promise-pool/?utm_campaign=PostD13&utm_medium=Post&utm_source=Post&gio_link_id=3oLQwOg9

/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    // creates a new promise to return
    return new Promise((resolve) => { 
        let pCount = 0; //counter for the running promises
        let fIdx = 0; // index for current function
        function solve() {

            //check if reached end
            if (fIdx >= functions.length) { 

                 // resolve if all promises are done
                if (pCount === 0) resolve();
                return;
            }

            // if we have limit and the array has more function to excecute, we will keep looping
            while (pCount < n && fIdx < functions.length) {

                pCount++; //increase the count of running promises
                const promise = functions[fIdx](); // get the function from the current index
                fIdx++; //increase the index for functions.


                //once the promise is resolved then block is called
                promise.then(() => { 

                    //decrease current running promise count as a promise is ended
                    pCount--; 

                //Recursively calling the function for next set of promises
                    solve(); 
                });
            }
        }

        //function calling
        solve();
    });
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */