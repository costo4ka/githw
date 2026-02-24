```
mkdir build
cd build
```

версия Visual Studio может отличаться
```
cmake .. -G "Visual Studio 16 2019"
```

## Docker инструкции
- Собрать и запустить контейнеры:
  ```bash
  docker-compose up --build -d
  ```
- Остановить и удалить контейнеры:
  ```bash
  docker-compose down
  ```

## Загрузка на Docker Hub
1. Залогиньтесь:
   ```bash
   docker login
   ```
2. Проставьте теги:
   ```bash
   docker tag test-repo-app:latest <ваш-логин>/test-repo-app:latest
   docker tag test-repo-web:latest <ваш-логин>/test-repo-web:latest
   ```
3. Загрузите на Docker Hub:
   ```bash
   docker push <ваш-логин>/test-repo-app:latest
   docker push <ваш-логин>/test-repo-web:latest
   ```

