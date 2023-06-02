// Webpage:https://leetcode.com/problems/promise-time-limit/description/?utm_campaign=PostD12&utm_medium=Post&utm_source=Post&gio_link_id=nombN5Z9

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    return async function(...args) {
      return new Promise((resolve, reject) => {
        const timeout = setTimeout(() => {
          reject("Time Limit Exceeded");
        }, t);
        fn(...args)
          .then(resolve)
          .catch(reject)
          .finally(() => clearTimeout(timeout));
      })
    }
  };
  
  /**
   * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
   * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
   */
