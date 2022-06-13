#!/usr/bin/env python3

import subprocess
import sys
import platform


def is_rosetta() -> bool:

    if platform.system() != "Darwin":
        return False

    if platform.machine() != "arm64":
        return False

    ret = subprocess.run(
        ["sysctl", "-n", "sysctl.proc_translated"], shell=False, capture_output=True, text=True
    )
    if ret.stderr:
        return False
    return ret.returncode == 1


if __name__ == "__main__":
    if is_rosetta():
        print(f"{sys.executable} running through Rosetta")
    else:
        print(f"{sys.executable} not using Rosetta")
