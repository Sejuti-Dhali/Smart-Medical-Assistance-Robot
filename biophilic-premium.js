"use strict";

/*
 * Biophilic Premium Enhancement
 * Presentation-only progressive enhancement.
 * Does not modify clinical data or application state.
 */

(function () {
  const reduced = window.matchMedia(
    "(prefers-reduced-motion: reduce)"
  );

  let observer = null;

  function visible(element) {
    if (element.hidden) return false;
    if (element.closest("[hidden]")) return false;

    const style = getComputedStyle(element);
    return (
      style.display !== "none" &&
      style.visibility !== "hidden"
    );
  }

  function enhanceScroll() {
    const header = document.querySelector(
      ".topbar,.navbar,.site-header,header"
    );

    if (!header) return;

    let queued = false;

    window.addEventListener("scroll",() => {
      if (queued) return;
      queued = true;

      requestAnimationFrame(() => {
        header.classList.toggle(
          "bio-scrolled",
          window.scrollY > 30
        );
        queued = false;
      });
    },{passive:true});
  }

  function enhanceReveal() {
    if (observer) observer.disconnect();

    const targets = document.querySelectorAll(
      ".feature,.card,.metric,.stat-card,.info-card"
    );

    if (
      reduced.matches ||
      !("IntersectionObserver" in window)
    ) {
      targets.forEach(el => {
        el.classList.add("bio-visible");
      });
      return;
    }

    observer = new IntersectionObserver(entries => {
      entries.forEach(entry => {
        if (!entry.isIntersecting) return;
        entry.target.classList.add("bio-visible");
        observer.unobserve(entry.target);
      });
    },{
      threshold: 0.04,
      rootMargin: "0px 0px 80px 0px"
    });

    targets.forEach(el => {
      if (!visible(el)) return;

      el.classList.add("bio-reveal");

      // Never hide important content when scripting is delayed.
      el.classList.add("bio-visible");
    });
  }

  function enhanceImages() {
    document.querySelectorAll("img").forEach(img => {
      if (!img.hasAttribute("loading")) {
        img.loading = "lazy";
      }

      if (!img.hasAttribute("decoding")) {
        img.decoding = "async";
      }
    });
  }

  function initialize() {
    enhanceScroll();
    enhanceImages();
    enhanceReveal();
  }

  if (document.readyState === "loading") {
    document.addEventListener(
      "DOMContentLoaded",
      initialize,
      {once:true}
    );
  } else {
    initialize();
  }

  window.addEventListener(
    "hashchange",
    () => requestAnimationFrame(enhanceReveal)
  );
})();