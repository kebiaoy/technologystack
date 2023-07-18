import os
import re
import subprocess
import sys
from shutil import copytree, rmtree, move
import Common

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("must input source dir and test program path")
        exit(-1)
    sourceDir = sys.argv[1]
    testProgramPath = sys.argv[2]
    command = ["OpenCppCoverage","--source",sourceDir,"--",testProgramPath]
    ret = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, encoding="utf-8",
                         timeout=60 * 20)
    runInfo = ret.stdout
    print("{}".format(runInfo))
    matchObj = re.search("Coverage generated in Folder(.+)\n", runInfo, re.M | re.I)
    if matchObj is None:
        print("can not find coverage")
        sys.exit(-1)
    groups = matchObj.groups()
    if len(groups) != 1:
        print("can not find coverage path groups {}".format(groups))
        sys.exit(-1)
    new_gen_path = matchObj.group(1).strip()
    if os.path.isdir(Common.get_coverage_site()):
        rmtree(Common.get_coverage_site())
    move(new_gen_path, Common.get_coverage_site())
    os.remove(os.path.join(os.getcwd(), "LastCoverageResults.log"))

    sys.exit(ret.returncode)

