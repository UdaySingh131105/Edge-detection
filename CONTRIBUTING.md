# Contributing to FlameEdgeViewer

Thanks for your interest in contributing! This document explains how to propose changes, run the project locally for development, and the preferred workflow for submitting patches.

## Quick Start

- Fork the repository and create a feature branch from `main`:

  ```bash
  git clone <your-fork-url>
  git checkout -b feature/your-short-description
  ```

- Make small, focused changes and include tests where practical.

## Code Style & Guidelines

- Keep Java/Android code idiomatic and follow Android/Kotlin/Java best practices used in the project.
- Native C++ code should be clear and performant; prefer readable code over micro-optimizations unless profiling proves otherwise.
- Format code before committing. If the project contains formatting scripts or IDE configs, use those.
- Avoid large, unrelated changes in a single PR — split into smaller PRs where possible.

## Building Locally

### Android app

- Build from project root (Windows):

  ```cmd
  .\gradlew.bat assembleDebug
  ```

- Install onto a connected device/emulator:

  ```cmd
  adb install -r app\build\outputs\apk\debug\app-debug.apk
  ```

- If you modify native code, the Gradle build will invoke CMake/NDK to rebuild the native libraries. Ensure your NDK/CMake versions match `local.properties` / `build.gradle` configuration.

### Web viewer

- From `web/`:

  ```cmd
  cd web
  npm install
  npm run dev
  ```

## Testing

- Manual tests: run the app on device/emulator and verify camera, mode switching, and rendering work as expected.
- If you add automated tests, include instructions to run them in your PR description.

## Branching and Pull Requests

- Branch from `main` and name branches like `feature/xxx`, `fix/xxx`, or `chore/xxx`.
- Keep the PR description clear: what changed, why, and how to test.
- Include screenshots, GIFs, or short videos for visual/UI changes.

## Review Checklist (for contributors)

- Does the change compile and run on a device or emulator?
- Are native binaries (if modified) built and packaged correctly?
- Is the change small and focused with a clear commit message?
- Are any new dependencies documented and necessary?

## Contributor Code of Conduct

Be respectful and collaborative. Treat maintainers and other contributors with courtesy. If you'd like, maintainers can add a formal `CODE_OF_CONDUCT.md`.

## Reporting Issues

- Open issues for bugs or enhancement requests with a clear title and reproduction steps.
- Provide device/emulator details and relevant logs when possible.

## Contact

If you need help getting set up, open an issue or mention the maintainers in a PR and they will assist.

Thank you for helping improve FlameEdgeViewer!
