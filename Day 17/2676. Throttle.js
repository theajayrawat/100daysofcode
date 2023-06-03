// Webpage:https://leetcode.com/problems/throttle/?utm_campaign=PostD16&utm_medium=Post&utm_source=Post&gio_link_id=bR7jOnr9

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function(fn, t) {
    let timeoutInProgress = null;
    let argsToProcess = null;

    const timeoutFunction = () => {
        if(argsToProcess===null){
            timeoutInProgress=null;
        }
        else{
            fn(...argsToProcess);
            argsToProcess = null;
            timeoutInProgress=setTimeout(timeoutFunction,t);
        }
    };

    return function(...args) {
        if(timeoutInProgress){
            argsToProcess = args;
        }
        else{
            fn(...args);
            timeoutInProgress=setTimeout(timeoutFunction,t);
        }
  }
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */