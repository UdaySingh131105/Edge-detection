 # 🔥 FlameEdgeViewer

 **Real-time camera edge detection and preview (Android + OpenCV C++ + OpenGL ES + Web Viewer)**

 FlameEdgeViewer is a lightweight research/demo project that captures camera frames on Android, processes them in native C++ (via JNI + OpenCV), and renders results using an OpenGL ES texture pipeline. A minimal web viewer (Vite + TypeScript) is included for quick visualization of sample outputs.

 ---

 **Highlights**

 - **Android (CameraX)** for low-latency camera capture
 - **C++ native pipeline (JNI + OpenCV)** for efficient image processing
 - **OpenGL ES 2.0** for GPU texture uploads and rendering
 - **Simple Web Viewer (Vite/TypeScript)** for demoing sample images

 ---

 **Table of Contents**

 - Overview
 - Quick Start
 - Building the Android app
 - Native / OpenCV notes
 - Running the Web Viewer
 - Project structure
 - Development & Contributing
 - Troubleshooting
 - License

 ---

 ## Overview

 The application pipeline is:

 1. CameraX captures frames (NV21/YUV).
 2. Frames are forwarded to native code through JNI.
 3. Native C++ (OpenCV) converts and processes frames (grayscale, Canny edges).
 4. Processed buffers are uploaded as textures to OpenGL ES and displayed in real time.

 The web viewer is separate and intended for quick previews of sample images included in `web/images/`.

 ## Quick Start (Windows)

 Prerequisites

 - Java JDK (11+ recommended)
 - Android SDK & NDK (matching project's `local.properties`/`ndkVersion`)
 - CMake (used by Gradle/ndk-build)
 - Node.js + npm (for the web viewer)
 - `adb` (Android platform-tools) for installing APKs

 1) Build the Android app (from project root):

 ```cmd
 cd C:\Projects\FlamEdgeViewer
 .\\gradlew.bat assembleDebug
 ```

 2) Install to a connected device/emulator:

 ```cmd
 adb install -r app\build\outputs\apk\debug\app-debug.apk
 ```

 3) Run the Web Viewer (in a separate terminal):

 ```cmd
 cd web
 npm install
 npm run dev
 ```

 Open the dev server URL (typically `http://localhost:5173`) to view the sample images.

 ## Building the Android app (details)

 - Run `gradlew.bat assembleDebug` or build from Android Studio.
 - Native code is built via CMake/NDK during the Gradle build. If you hit native build issues, confirm your `ANDROID_NDK_HOME` (or NDK path in `local.properties`) and installed NDK version.
 - APK output: `app\\build\\outputs\\apk\\debug\\app-debug.apk` (for the debug build)

 ## Native / OpenCV notes

 - The native code lives in `app/src/main/cpp/` and is exposed to Java via JNI. Look for files named like `native-lib.cpp` (or similarly named JNI bridge).
 - OpenCV headers and binaries are present under the `opencv/` folder and prebuilt libraries under `libs/`/`staticlibs/`. The Gradle/CMake scripts are configured to link those native libs into the APK's native libraries.
 - Common processing steps implemented in native code:
	 - NV21 (YUV) → BGR conversion
	 - Grayscale conversion
	 - Canny edge detection
	 - Packaging raw bytes for GPU texture upload

 If you need to rebuild OpenCV yourself, follow the OpenCV cross-compilation docs and update `CMakeLists.txt` or `OpenCVConfig.cmake` accordingly.

 ## Web Viewer (demo)

 The `web` folder contains a small Vite app that demonstrates sample processed images and a simple UI to toggle images.

 Commands (from `web/`):

 ```cmd
 npm install
 npm run dev
 ```

 Production build (optional):

 ```cmd
 npm run build
 npm run preview
 ```

 The viewer is not integrated with the Android app at runtime; it's intended for quick browser-based demos.

 ## Project Structure

 ```
 FlameEdgeViewer/
 ├─ app/                      # Android application module
 │  ├─ src/main/java/         # Java/Kotlin app code (CameraX, UI, JNI callers)
 │  ├─ src/main/cpp/          # Native C++ code (JNI wrappers, OpenCV processing)
 │  ├─ src/main/jniLibs/      # Prebuilt native libs (ABI folders)
 │  └─ CMakeLists.txt         # Native build config
 ├─ opencv/                   # OpenCV binaries / configs / cmake files
 ├─ libs/                     # Prebuilt Android libs (if present)
 ├─ web/                      # Vite + TypeScript demo viewer
 └─ FlameEdgeViewer_README.md  # This file
 ```

 ## Development & Contributing

 - To add a new processing mode, implement it in `app/src/main/cpp/` and expose a JNI function to switch modes from Java.
 - Keep UI / rendering logic on the Java side minimal; heavy processing should remain in native C++ for performance.
 - If adding dependencies, prefer Gradle-managed or documented native libs in `opencv/`.

 Contributing guidelines

 - Fork the repo and create a feature branch.
 - Open a pull request with a clear description and small, focused changes.
 - Include screenshots or short video clips for visual features.

 ## Troubleshooting

 - Build failures (native/CMake): confirm NDK/CMake versions and `local.properties` paths.
 - Missing OpenCV symbols at runtime: ensure native libs are bundled under `app/src/main/jniLibs/<abi>/` and the APK contains them (inspect with `apktool` or unzip the APK).
 - Camera permission crashes: ensure `CAMERA` permission is requested at runtime (Android 6.0+) and granted in app settings.