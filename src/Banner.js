import React, {useState, useEffect} from 'react';
import instance from './axios';
import requests from './requests';

function Banner() {

    const [movie, setMovie] = useState([]);

    useEffect(() => {
        async function fetchData() {
            const request = await instance.get(requests.fetchNetflixOriginals);
            setMovie(request.data.results[Math.floor(Math.random() * request.data.results.length - 1)]);
            console.log(request);
            console.log(Math.floor(Math.random() * request.data.results.length - 1));
            return request;
            
        }
        fetchData();
    }, [])

    // console.log(movie)

    return (
        <header className="banner" style={{
            backgroundSize: "cover",
            backgroundImage: `url("https://image.tmdb.org/t/p/original${movie.backdrop_path}")`,
            backgroundPosition: "center center"}}>
            <div className="banner__contents">
                {/* title */}
                <h1 className="banner__title">{movie.name || movie.title || movie.original_name}</h1>

                {/* div > 2 buttons */}
                <div className="banner__buttons">
                    <button className="banner__button">Play</button>
                    <button className="banner__button">My List</button>
                </div>

                {/* description */}
                <h1 className="banner__description">
                    {movie.overview}
                </h1>
            </div>
            {/* Fading Functionality */}
            <div className="banner__fadeBottom"></div>
        </header>
    )
}

export default Banner
