FROM php:7.4-cli
RUN mkdir -p /usr/src/myapp
COPY soal/index.php /usr/src/myapp
COPY soal/secrets.php /usr/src/myapp
WORKDIR /usr/src/myapp
CMD [ "php", "-S", "0.0.0.0:8000"]
EXPOSE 8000

