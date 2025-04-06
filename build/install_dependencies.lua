function install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local EXPECTED_SHA = '1581d4227c29aff056c101391b1c5f02622ff6ee881705dd08401e6cecaafafe'
    if hasher.get_value() == EXPECTED_SHA then
        return
    end

    darwin.dtw.remove_any("dependencies")

    os.execute("mkdir -p dependencies")
    
    os.execute("curl -L https://github.com/OUIsolutions/Universal-Garbage-Colector/releases/download/3.0.0/UniversalGarbage.c -o dependencies/UniversalGarbage.c")
    os.execute("curl -L https://github.com/OUIsolutions/Universal-Garbage-Colector/releases/download/3.0.0/UniversalGarbage.h -o dependencies/UniversalGarbage.h")   


    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: " .. new_hasher.get_value())
end
