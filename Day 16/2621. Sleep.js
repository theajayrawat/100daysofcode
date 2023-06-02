// Webpage:https://leetcode.com/problems/sleep/description/?utm_campaign=PostD11&utm_medium=Post&utm_source=Post&gio_link_id=5Rp2Wmzo

/**
 * @param {number} millis
 */
async function sleep(millis) {
    return new Promise((resolve,reject) => {
      try {
        setTimeout(() => resolve(), millis)
      } catch(err) {
        reject(err)
      }
    })
  }
  
  /** 
   * let t = Date.now()
   * sleep(100).then(() => console.log(Date.now() - t)) // 100
   */