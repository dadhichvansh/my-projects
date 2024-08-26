document.querySelectorAll('.navbar-nav a').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();
        const target = document.querySelector(this.getAttribute('href'));
        window.scrollTo({
            top: target.offsetTop - 70, // Adjusts for the navbar height
            behavior: 'smooth'
        });
    });
});

window.addEventListener('scroll', function () {
    const navbar = document.querySelector('.navbar');
    if (window.pageYOffset > 100) {
        navbar.classList.add('sticky');
    } else {
        navbar.classList.remove('sticky');
    }
});

const galleryImages = document.querySelectorAll('.gallery-image');

galleryImages.forEach(image => {
    image.addEventListener('mouseover', () => {
        image.style.transform = 'scale(1.1)';
        image.style.opacity = '0.8';
    });

    image.addEventListener('mouseout', () => {
        image.style.transform = 'scale(1)';
        image.style.opacity = '1';
    });
});

const bookNowButton = document.querySelector('.btn-book-now');

bookNowButton.addEventListener('mouseover', () => {
    bookNowButton.classList.add('pop');
});

bookNowButton.addEventListener('mouseout', () => {
    bookNowButton.classList.remove('pop');
});

const styleSheet = document.styleSheets[0];
styleSheet.insertRule(`
    @keyframes pop {
        0% { transform: scale(1); }
        50% { transform: scale(1.1); }
        100% { transform: scale(1); }
    }
`, styleSheet.cssRules.length);

styleSheet.insertRule(`
    .pop {
        animation: pop 0.3s ease-in-out;
    }
`, styleSheet.cssRules.length);

// Map Hover Shadow Effect
const mapIframe = document.querySelector('.map-iframe');

mapIframe.addEventListener('mouseover', () => {
    mapIframe.style.boxShadow = '0 0 20px rgba(0, 0, 0, 0.2)';
});

mapIframe.addEventListener('mouseout', () => {
    mapIframe.style.boxShadow = '0 0 10px rgba(0, 0, 0, 0.1)';
});
